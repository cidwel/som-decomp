.setcpu "65816"
.segment "CODE"
.org $11D0
map_control_0d11d0:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
