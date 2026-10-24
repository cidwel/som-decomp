.setcpu "65816"
.segment "CODE"
.org $A19D
map_control_0ea19d:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $D5 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
