.setcpu "65816"
.segment "CODE"
.org $BFEF
map_control_0dbfef:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
