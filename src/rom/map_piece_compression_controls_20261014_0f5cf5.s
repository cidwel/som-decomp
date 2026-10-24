.setcpu "65816"
.segment "CODE"
.org $5CF5
map_control_0f5cf5:
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
