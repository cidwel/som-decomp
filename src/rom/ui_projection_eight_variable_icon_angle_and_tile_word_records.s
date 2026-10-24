.setcpu "65816"
.segment "RODATA"
; Native consumer data at $C1FEF2; no graphics payload.
ui_angular_icon_0:
.word $0000 ; angular position, bit0080 selects four tiles
.word $3104, $3100, $7104
ui_angular_icon_1:
.word $0080 ; angular position, bit0080 selects four tiles
.word $3104, $3100, $3101, $7104
ui_angular_icon_2:
.word $0100 ; angular position, bit0080 selects four tiles
.word $3104, $3101, $7104
ui_angular_icon_3:
.word $0180 ; angular position, bit0080 selects four tiles
.word $3104, $3102, $3101, $7104
ui_angular_icon_4:
.word $0200 ; angular position, bit0080 selects four tiles
.word $3104, $3102, $7104
ui_angular_icon_5:
.word $0280 ; angular position, bit0080 selects four tiles
.word $3104, $3102, $3103, $7104
ui_angular_icon_6:
.word $0300 ; angular position, bit0080 selects four tiles
.word $3104, $3103, $7104
ui_angular_icon_7:
.word $0380 ; angular position, bit0080 selects four tiles
.word $3104, $3100, $3103, $7104
