.setcpu "65816"
.segment "CODE"
.org $99E5
map_control_0f99e5:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
