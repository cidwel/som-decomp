.setcpu "65816"
.segment "CODE"
.org $AD97
map_control_0ead97:
    .byte $C9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
