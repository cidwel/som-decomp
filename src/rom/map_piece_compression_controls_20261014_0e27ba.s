.setcpu "65816"
.segment "CODE"
.org $27BA
map_control_0e27ba:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
