
void lightModes() {
  switch (lightMode) {

    //can be used to chancge to any color
    case SINGLE_COLOR:
      singleColorMode();
      break;

    //adaptive lights
    case AMBIENT:
      ambientMode();
      break;

    //Colors switching disco style
    case DISCO:
      discoMode();
      break;

  }
}
