.setcpu "65816"
.segment "CODE"
.org $6BE5
map_control_0f6be5:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
