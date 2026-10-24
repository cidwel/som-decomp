.setcpu "65816"
.segment "CODE"
.org $E9BA
map_control_0de9ba:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
