.setcpu "65816"
.segment "CODE"
.org $0C24
map_control_0e0c24:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
