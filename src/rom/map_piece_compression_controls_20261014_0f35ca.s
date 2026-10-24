.setcpu "65816"
.segment "CODE"
.org $35CA
map_control_0f35ca:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
