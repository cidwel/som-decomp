.setcpu "65816"
.segment "CODE"
.org $535C
map_control_0f535c:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
