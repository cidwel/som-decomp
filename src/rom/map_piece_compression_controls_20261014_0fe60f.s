.setcpu "65816"
.segment "CODE"
.org $E60F
map_control_0fe60f:
    .byte $CF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C3 ; same-value copy count/distance
