.setcpu "65816"
.segment "CODE"
.org $8374
map_control_0c8374:
    .byte $C3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
