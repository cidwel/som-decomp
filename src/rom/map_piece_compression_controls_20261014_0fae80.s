.setcpu "65816"
.segment "CODE"
.org $AE80
map_control_0fae80:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
