.setcpu "65816"
.segment "CODE"
.org $C872
map_control_0fc872:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
