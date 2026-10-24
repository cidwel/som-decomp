.setcpu "65816"
.segment "CODE"
.org $565B
map_control_0f565b:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
