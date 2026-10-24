.setcpu "65816"
.segment "CODE"
.org $AFA3
map_control_0fafa3:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
