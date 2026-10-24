.setcpu "65816"
.segment "CODE"
.org $90B2
map_control_0f90b2:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
