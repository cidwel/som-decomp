.setcpu "65816"
.segment "CODE"
.org $484D
map_control_0c484d:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
