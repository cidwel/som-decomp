.setcpu "65816"
.segment "CODE"
.org $C651
map_control_0ec651:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
