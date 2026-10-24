.setcpu "65816"
.segment "CODE"
.org $F594
map_control_0df594:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
