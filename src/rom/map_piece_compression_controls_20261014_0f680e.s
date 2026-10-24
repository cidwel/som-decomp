.setcpu "65816"
.segment "CODE"
.org $680E
map_control_0f680e:
    .byte $C7 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
