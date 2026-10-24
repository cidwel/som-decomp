.setcpu "65816"
.segment "CODE"
.org $4A0D
map_control_0e4a0d:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E4 ; previous-row copy count
