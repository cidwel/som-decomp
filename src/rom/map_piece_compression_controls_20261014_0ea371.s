.setcpu "65816"
.segment "CODE"
.org $A371
map_control_0ea371:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
