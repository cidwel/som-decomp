.setcpu "65816"
.segment "CODE"
.org $84DB
map_control_0d84db:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
