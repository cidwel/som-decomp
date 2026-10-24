.setcpu "65816"
.segment "CODE"
.org $55B9
map_control_0c55b9:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
