.setcpu "65816"
.segment "CODE"
.org $B0A3
map_control_0db0a3:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
