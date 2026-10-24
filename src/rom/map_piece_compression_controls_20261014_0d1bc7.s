.setcpu "65816"
.segment "CODE"
.org $1BC7
map_control_0d1bc7:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
