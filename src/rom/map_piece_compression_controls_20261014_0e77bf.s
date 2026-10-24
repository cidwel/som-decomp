.setcpu "65816"
.segment "CODE"
.org $77BF
map_control_0e77bf:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
