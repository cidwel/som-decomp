.setcpu "65816"
.segment "CODE"
.org $10A5
map_control_0f10a5:
    .byte $D1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
