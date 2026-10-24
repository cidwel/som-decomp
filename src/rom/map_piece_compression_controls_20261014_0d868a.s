.setcpu "65816"
.segment "CODE"
.org $868A
map_control_0d868a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
