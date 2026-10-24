.setcpu "65816"
.segment "CODE"
.org $FFC1
map_control_0dffc1:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
