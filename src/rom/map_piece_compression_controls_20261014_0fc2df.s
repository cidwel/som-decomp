.setcpu "65816"
.segment "CODE"
.org $C2DF
map_control_0fc2df:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
