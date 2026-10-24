.setcpu "65816"
.segment "CODE"
.org $0818
map_control_0d0818:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
