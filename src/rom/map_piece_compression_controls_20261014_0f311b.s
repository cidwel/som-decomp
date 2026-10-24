.setcpu "65816"
.segment "CODE"
.org $311B
map_control_0f311b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
