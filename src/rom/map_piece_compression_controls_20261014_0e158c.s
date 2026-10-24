.setcpu "65816"
.segment "CODE"
.org $158C
map_control_0e158c:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
