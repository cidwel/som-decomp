.setcpu "65816"
.segment "CODE"
.org $1A29
map_control_0e1a29:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $CB ; same-value copy count/distance
