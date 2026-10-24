.setcpu "65816"
.segment "CODE"
.org $9FB1
map_control_0e9fb1:
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
