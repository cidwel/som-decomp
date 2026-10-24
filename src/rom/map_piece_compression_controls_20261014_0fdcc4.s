.setcpu "65816"
.segment "CODE"
.org $DCC4
map_control_0fdcc4:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $E2 ; previous-row copy count
