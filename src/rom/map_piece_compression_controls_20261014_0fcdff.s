.setcpu "65816"
.segment "CODE"
.org $CDFF
map_control_0fcdff:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E5 ; previous-row copy count
