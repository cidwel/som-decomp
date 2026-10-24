# Native optional general-menu coordinate tiles

D0DE29/89 checks the real CFF5 display flag, sets the original display workspace and splits the two actor coordinate words through D0DEE1/11. It uploads four original digit tiles at7500/7510/7600/7610 through D0DE82/95 and waits on the real public vblank service. Tile expansion reads the original D9FF08 glyph data, writes the8100 workspace and triggers channel5 DMA of32 bytes with the native PPU/register settings. No glyph/ROM payload is exported.

Smoke2 and the first full6 passed: disabled/enabled public path, minimum/maximum digit selection and coordinate conversion0/FFFF. All85/85 own starts and widths are observed,195 distinct PCs and493 captured dependency hashes remain unchanged. CPU/context/WRAM and the literal render/audio/arithmetic/input peripherals match. The enabled entry executes its actual extra vblank event after all four native DMA transfers; fixture setup frames are not counted as additional source coverage.

The incoming context is the general-menu producer's normalized DB0/D0, binary arithmetic and M16/X16. Three bodies total195 candidate new instruction bytes. The general caller and equipment-flight completion are being composed separately; these coordinate helpers do not imply their closure.

Integration spec: `event_menu_coordinates_check:EventMenuCoordinates:event-menu-coordinates:event_menu_coordinates`.

## Frozen hashes

- `tools/event_menu_coordinates.py`: `33c87c01d2dd226ae579c76d2d2a3dc833417241b75fb382eb72089c50d2dc0e`
- `tools/event_menu_coordinates_check.py`: `a1aba43308e68ec196c01747c14c42450c03c4688c8e3627f65714270c1aae0a`
- `data/event_menu_coordinates.json`: `0a2f362668f543ed0f07e5c9c4996321c947b15e6fafcc421b76c2b3b271cfc5`
- `data/event_menu_coordinates.coverage.json`: `5d259661914351806cda13d87e9359c8d19489d6fbe474e1de4ce2b93ee80366`
- `data/event_menu_coordinates.source_audit.json`: `5717711478561d993f6e85a297d2a17b420d8e2d8f90daa6b3f0c0ee63fa96ac`
