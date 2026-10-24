.setcpu "65816"
.segment "CODE"
.org $B878
map_control_0eb878:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
