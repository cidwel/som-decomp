.setcpu "65816"
.segment "CODE"
.org $EADC
map_control_0deadc:
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
