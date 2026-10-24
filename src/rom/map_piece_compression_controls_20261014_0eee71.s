.setcpu "65816"
.segment "CODE"
.org $EE71
map_control_0eee71:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
