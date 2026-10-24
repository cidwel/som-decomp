.setcpu "65816"
.segment "CODE"
.org $749B
map_control_0d749b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
