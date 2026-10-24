.setcpu "65816"
.segment "CODE"
.org $DBC5
map_control_0fdbc5:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
