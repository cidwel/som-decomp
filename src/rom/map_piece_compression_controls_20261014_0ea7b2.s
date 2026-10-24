.setcpu "65816"
.segment "CODE"
.org $A7B2
map_control_0ea7b2:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C6 ; same-value copy count/distance
