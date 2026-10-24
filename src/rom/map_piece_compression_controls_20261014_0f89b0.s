.setcpu "65816"
.segment "CODE"
.org $89B0
map_control_0f89b0:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E6 ; previous-row copy count
