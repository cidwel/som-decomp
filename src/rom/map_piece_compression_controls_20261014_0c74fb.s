.setcpu "65816"
.segment "CODE"
.org $74FB
map_control_0c74fb:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
