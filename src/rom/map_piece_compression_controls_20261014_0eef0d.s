.setcpu "65816"
.segment "CODE"
.org $EF0D
map_control_0eef0d:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
