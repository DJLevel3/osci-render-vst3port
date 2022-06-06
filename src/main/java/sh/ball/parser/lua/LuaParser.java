package sh.ball.parser.lua;

import org.luaj.vm2.lib.jse.JsePlatform;
import sh.ball.audio.FrameSource;
import sh.ball.parser.FileParser;
import sh.ball.shapes.Vector2;

import javax.script.*;
import java.io.*;
import java.util.stream.Collectors;

public class LuaParser extends FileParser<FrameSource<Vector2>> {

  private String script;

  public LuaParser(InputStream inputStream) {
    this.script = new BufferedReader(new InputStreamReader(inputStream))
      .lines().collect(Collectors.joining("\n"));
  }

  @Override
  public String getFileExtension() {
    return "lua";
  }

  @Override
  public FrameSource<Vector2> parse() throws Exception {
    ScriptEngineManager sem = new ScriptEngineManager();
    Compilable e = (Compilable) sem.getEngineByName("luaj");
    CompiledScript compiledScript = e.compile(script);

    return new LuaSampleSource(compiledScript);
  }

  public static boolean isLuaFile(String path) {
    return path.matches(".*\\.lua");
  }
}