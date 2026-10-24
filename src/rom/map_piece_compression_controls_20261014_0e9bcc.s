.setcpu "65816"
.segment "CODE"
.org $9BCC
map_control_0e9bcc:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
