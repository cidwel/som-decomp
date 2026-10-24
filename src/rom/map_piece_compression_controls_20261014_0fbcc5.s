.setcpu "65816"
.segment "CODE"
.org $BCC5
map_control_0fbcc5:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
