.setcpu "65816"
.segment "CODE"
.org $1DCA
map_control_0f1dca:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
