.setcpu "65816"
.segment "CODE"
.org $467D
map_control_0e467d:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
